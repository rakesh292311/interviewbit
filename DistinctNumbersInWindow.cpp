#include <list>
vector<int> Solution::dNums(vector<int> &A, int B) {
    vector< int> result;
    if (A.size() == 0)
        return result;
    list<int> m_queue;
    map<int, int> m_map;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (m_queue.size() < B)
            m_queue.push_back(A[i]);
        else
        {
            list<int>::iterator lit;
            m_map.clear();
            for (lit = m_queue.begin(); lit != m_queue.end(); lit++)
            {
                if (m_map.find(*lit) == m_map.end())
                    m_map[*lit] = 1;

            }
            result.push_back(m_map.size());
            m_queue.pop_front();
            m_queue.push_back(A[i]);
        }
    }
    list<int>::iterator lit;
    m_map.clear();
    for (lit = m_queue.begin(); lit != m_queue.end(); lit++)
    {
        if (m_map.find(*lit) == m_map.end())
            m_map[*lit] = 1;

    }
    result.push_back(m_map.size());
    return result;
}
