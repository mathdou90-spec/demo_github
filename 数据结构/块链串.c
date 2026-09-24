#include <stdio.h>
#include <stdlib.h>

#define CHUNK 4
//块的定义
typedef struct Chunk {
    char data[CHUNK];
    int used;
    struct Chunk *next;
} Chunk;
//串的定义
typedef struct {
    Chunk *head, *tail;
    int Length;
} LString;
//初始化串
void initLString(LString *s) {
    s->head = s->tail = NULL;
    s->Length = 0;
}
//销毁串
void destroyLString(LString *s) {
    while (s->head) {
        Chunk *temp = s->head;
        s->head = s->head->next;
        free(temp);
    }
    s->tail = NULL;
    s->Length = 0;
}
//定位块
Chunk* Locate(const LString *s,int pos,int *off) {
    if(pos<1 || pos>s->Length) {
        return NULL;
    }
    int q=(pos-1)/CHUNK;
    *off=(pos-1)%CHUNK;
    Chunk* p=s->head;
    while(q-->0) p=p->next; 
    return p;
}
//在块内找到字符
int GetChar(const LString *s,int pos,char *out) {
    int off;
    Chunk *p=Locate(s,pos,&off);
    if(!p) return 0;
    *out=p->data[off];
    return 1;
}
//尾插
int AppendChar(LString *s,char c) {
    //如果尾块不存在或者尾块已满，则申请新块
    if(!s->tail||s->tail->used==CHUNK) {
        Chunk *p=malloc(sizeof *p);
        if(!p) return 0;
        p->used=0;
        p->next=NULL;
        //有尾则直接插入新块，否则新块为头块
        if(s->tail) {
            s->tail->next=p;
        } else {
            s->head=p;
        }
        s->tail=p;
    }
    s->tail->data[s->tail->used++]=c;
    s->Length++;
    return 1;
}
//中间插入
int InsertChar(LString *s,int pos,char c) {
    //如果插入位置不合法，则返回0
    if(pos<1||pos>s->Length+1) return 0;
    if(pos==s->Length+1) return AppendChar(s,c);
    //定位到插入位置的块和偏移量
    int off;
    Chunk *p=Locate(s,pos,&off);
    char carry=c;
    while(p) {
        //块内移动
        for(int i=off;i<p->used;i++) {
            char temp=p->data[i];
            p->data[i]=carry;
            carry=temp;
        }
        //补全空位
        if(p->used<CHUNK) {
            p->data[p->used++]=carry;
            s->Length++;
            return 1;
        }
        //如果块已满，则将carry传递到下一块
        p=p->next;
        off=0;
    }
    return AppendChar(s,carry);
}
//删除字符
int DeleteChar(LString *s,int pos) {
    //如果删除位置不合法，则返回0
    if(pos<1||pos>s->Length) return 0;
    //定位到删除位置的块和偏移量
    int off;
    Chunk *p=Locate(s,pos,&off);
    while(p) {
        //块内移动
        for(int i=off;i<p->used-1;i++) {
            p->data[i]=p->data[i+1];
        }
        //如果有下一块，则将下一块的第一个字符传递过来
        if(p->next) {
            p->data[p->used-1]=p->next->data[0];
            p=p->next;
            off=0;
        } else {
            p->used--;
            s->Length--;
            //如果尾块为空，则释放尾块
            if(p->used==0) {
                if(s->head==s->tail) {
                    free(s->head);
                    s->head=s->tail=NULL;
                } else {
                    Chunk *temp=s->head;
                    while(temp->next!=s->tail) temp=temp->next;
                    free(s->tail);
                    s->tail=temp;
                    s->tail->next=NULL;
                }
            }
            return 1;
        }
    }
    return 1;
}