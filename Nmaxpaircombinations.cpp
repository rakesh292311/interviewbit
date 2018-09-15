vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> result;
    if (A.size() != B.size())
        return result;
    multimap<int, int> m_map;
    for (int i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j <B.size(); j++)
        {
            int sum = A[i] + B[j];
            m_map.insert(pair<int, int>(sum, i));
        }
    }
    multimap<int, int>::reverse_iterator rit;
    int i;
    for (rit = m_map.rbegin(), i = 0; i < A.size(); i++, rit++)
    {
        result.push_back(rit->first);
    }
    return result;
}
