#include <list>
struct page {
    int key;
    int val;
};

map<int, page> m_map;
list<page> m_list;
int m_capacity;
LRUCache::LRUCache(int capacity) {

    m_capacity = capacity;
    m_list.clear();
    m_map.clear();
}

int LRUCache::get(int key) {

    if (m_map.find(key) != m_map.end())
    {
        page temp = m_map.find(key)->second;
        list<page>::iterator it = m_list.begin();
        for (it; it != m_list.end(); it++)
        {
            if (it->key == temp.key)
                break;
        
        }
        m_list.erase(it);
        m_list.push_back(temp);
        return    m_map.find(key)->second.val;
    }
    return -1;
}

void LRUCache::set(int key, int value) {
    page temp;
    if (m_map.find(key) != m_map.end())
    {
        page temp = m_map.find(key)->second;
        list<page>::iterator it = m_list.begin();
        for (it; it != m_list.end(); it++)
        {
            if (it->key == temp.key)
                break;

        }
        m_list.erase(it);
        temp.val = value;
        m_list.push_back(temp);
        m_map.find(key)->second.val = value;
        return;
    }
    if (m_list.size() == m_capacity)
    {
        temp = m_list.front();
        m_list.pop_front();
        m_map.erase(temp.key);
    }
    temp.key = key;
    temp.val = value;
    m_list.push_back(temp);
    m_map[key] = temp;

}
