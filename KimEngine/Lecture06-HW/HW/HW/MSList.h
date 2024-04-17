﻿#pragma once
#include "MObject.h" 

template <typename T>
class MSNode
{
public:
    MSNode(T data) : data(data), next_node(nullptr) {}
    ~MSNode() {}

    T data;
    MSNode* next_node;
};

template <typename T>
class MSList
{
public:
    MSList() : _head(nullptr), _size(0) {}
    ~MSList() {}

    int get_size() const { return _size; }
    void push_back(T data); //푸쉬백 사용 없으면 오류뜸
    T& operator[](int index);
    void clear();

public:
    MSNode<T>* _head;
    int _size;
};
template <typename T>
T& MSList<T>::operator[](int index)//oper사용 
{
    // 인덱스가 유효한지 확인
    if (index < 0 || index >= _size)
    {
        std::cerr << "Invalid index\n";
        exit(1);
    }

    // 인덱스에 해당하는 노드 찾기
    MSNode<T>* current = _head;
    for (int i = 0; i < index; ++i)
    {
        current = current->next_node;
    }

    // 해당 노드의 데이터 반환
    return current->data;
}template <typename T>
void MSList<T>::push_back(T data)
{
    MSNode<T>* new_node = new MSNode<T>(data);
    if (!_head)
    {
        _head = new_node;
    }
    else
    {
        MSNode<T>* current = _head;
        while (current->next_node)
        {
            current = current->next_node;
        }
        current->next_node = new_node;
    }
    _size++;
}template <typename T>
void MSList<T>::clear()
{
    while (_head)
    {
        MSNode<T>* temp = _head;
        _head = _head->next_node;
        delete temp;
    }
    _size = 0;
}
