// 控制块基类（虚析构用于多态删除）
class control_block_base {
public:
    virtual void dispose() noexcept = 0;   // 销毁对象
    virtual ~control_block_base() = default;
};

// 具体控制块，包含引用计数、弱计数和删除器
template<typename T, typename Deleter>
class control_block_impl : public control_block_base {
private:
    T* ptr;                // 指向被管理的对象
    Deleter deleter;        // 删除器
    std::atomic<long> ref_count;   // 强引用计数
    std::atomic<long> weak_count;  // 弱引用计数（用于支持weak_ptr）

public:
    control_block_impl(T* p, Deleter d)
        : ptr(p), deleter(std::move(d)), ref_count(1), weak_count(0) {}

    void add_ref() noexcept { ref_count.fetch_add(1, std::memory_order_relaxed); }
    void release() noexcept {
        if (ref_count.fetch_sub(1, std::memory_order_acq_rel) == 1) {
            dispose();               // 强引用归零，销毁对象
            if (weak_count.load(std::memory_order_acquire) == 0) {
                delete this;         // 弱引用也为零，销毁控制块
            }
        }
    }

    void add_weak_ref() noexcept { weak_count.fetch_add(1, std::memory_order_relaxed); }
    void release_weak() noexcept {
        if (weak_count.fetch_sub(1, std::memory_order_acq_rel) == 1 &&
            ref_count.load(std::memory_order_acquire) == 0) {
            delete this;             // 弱引用归零且对象已销毁，销毁控制块
        }
    }

    void dispose() noexcept override {
        if (ptr) {
            deleter(ptr);  // 调用自定义删除器销毁对象
        }
    }

    long use_count() const noexcept {
        return ref_count.load(std::memory_order_acquire);
    }
};