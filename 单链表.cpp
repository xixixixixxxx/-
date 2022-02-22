#include<iostream>
using namespace std;

struct LNode {
	int data;
	LNode* next;
};

typedef LNode* LinkList;

//初始化一个不带头结点的单链表
bool initList(LinkList& head) {
	head = NULL;
	return true;
}

//初始化一个带头结点的单链表(建议使用)
bool InitList(LinkList& head) {
	head = new LNode;
	if (head == NULL)
		return false;
	head->next = NULL;
	return true;
}

//链表的插入(带头结点)
bool listInsert(LinkList& head, int i, int e) {
	//找到第 i - 1 个结点
	LNode* p = getElem(head, i - 1);

	//插入新节点
	return insertNextNode(p, e);
}

//链表插入（不带头结点）
bool ListInsert(LinkList& head, int i, int e) {
	//若 i = 1，进行特殊处理
	if (i == 1) {
		LNode* s = new LNode;
		s->data = e;
		s->next = head;
		head = s;
		return true;
	}
	//i != 1的处理
	//找到第 i - 1 个结点
	LNode* p = getElem(head, i - 1);
	//插入新结点
	return insertNextNode(p, e);
}

//后插操作：在p结点之后插入元素 e
bool insertNextNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = new LNode;
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//前插操作：在p结点之前插入元素e
bool insertPriorNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = new LNode;
	if (s == NULL)
		return false;
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}

//删除给定结点
bool listDelete(LinkList& head, int i, int& e) {
	if (i < 1)
		return false;
	LNode* p;
	p = head;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL)
		return false;
	e = p->next->data;
	p->next = p->next->next;
	return true;
}

//删除指定结点p
bool deleteNode(LNode* p) {
	if (p == NULL)
		return false;
	LNode* q = p->next;
	p->data = q->data;
	p->next = q->next;
	return true;
	delete q;
}

//按位查找，返回第i个结点（带头结点）
LNode* getElem(LinkList& head, int i) {
	if (i < 0)
		return NULL;
	LNode* p;
	int j = 0;
	p = head;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

//按值查找，找到数据域为e的结点（带头结点）
LNode* locateElem(LinkList& head, int e) {
	LNode* p = head->next;
	//从第一个结点开始查找数据域为e的结点
	while (p != NULL && p->data != e)
		p = p->next;
	return p;//如果存在返回该节点，不存在返回NULL
}

//求表长(带头结点)
int length(LinkList& head) {
	LNode* p = head->next;
	int len = 1;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList& head) {
	int x;
	head = new LNode;
	LNode* s,*l;
	l = head;
	cin >> x;
	do {
		s = new LNode;
		s->data = x;
		l->next = s;
		l = s;
		cin >> x;
	} while (x != 9999);
	l->next = NULL;
	return head;
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList& head) {
	int x;
	LNode* s;
	head = new LNode;
	head->next = NULL;
	cin >> x;
	while (x != 9999) {
		s = new LNode;
		s->data = x;
		s->next = head->next;
		head->next = s;
		cin >> x;
	}
	return head;
}