class Solution
{
public:
    void Permutation(int index, int size, string s, unordered_set<string> &Ans)
    {
        if (index >= size)
        {
            Ans.insert(s);
            return;
        }

        for (int i = index; i < size; i++)
        {
            swap(s[index], s[i]);
            Permutation(index + 1, size, s, Ans);
            swap(s[index], s[i]);
        }
    }

    vector<string> findPermutation(string &s)
    {
        unordered_set<string> Ans;

        Permutation(0, s.size(), s, Ans);

        return vector<string>(Ans.begin(), Ans.end());
    }
};