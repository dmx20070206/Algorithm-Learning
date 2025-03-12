// http://bailian.openjudge.cn/practice/2811/

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

void push_button(int i, int j, vector<vector<int>> &lights)
{
    if (i < 0 || j < 0 || i > lights.size() || j > lights[0].size())
    {
        return;
    }
    lights[i][j] = !lights[i][j];
    if (i - 1 >= 0)
        lights[i - 1][j] = 1 - lights[i - 1][j];
    if (i + 1 < lights.size())
        lights[i + 1][j] = 1 - lights[i + 1][j];
    if (j + 1 < lights[0].size())
        lights[i][j + 1] = 1 - lights[i][j + 1];
    if (j - 1 >= 0)
        lights[i][j - 1] = 1 - lights[i][j - 1];
}

bool verify(string input, vector<vector<int>> lights, vector<vector<int>> &anwser)
{
    for (int i = 0; i < lights.size(); i++)
    {
        if (input[i] == '1')
        {
            push_button(i, 0, lights);
            anwser[i][0] = 1;
        }
    }

    for (int j = 1; j < lights[0].size(); j++)
    {
        for (int i = 0; i < lights.size(); i++)
            if (lights[i][j - 1])
            {
                push_button(i, j, lights);
                anwser[i][j] = 1;
            }
    }

    for (int i = 0; i < lights.size(); i++)
    {
        if (lights[i][lights[0].size() - 1])
            return false;
    }
    return true;
}

int main()
{
    vector<vector<int>> lights(5, vector<int>(6, 0));
    vector<vector<int>> anwser(5, vector<int>(6, 0));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> lights[i][j];
        }
    }
    for (int i = 0; i < 32; i++)
    {
        string binary = bitset<5>(i).to_string();
        if (verify(binary, lights, anwser))
        {
            for (int j = 0; j < anwser.size(); j++)
            {
                for (int k = 0; k < anwser[0].size(); k++)
                {
                    cout << anwser[j][k] << " ";
                }
                cout << endl;
            }
            break;
        }
        for (int i = 0; i < anwser.size(); i++)
            for (int j = 0; j < anwser[0].size(); j++)
                anwser[i][j] = 0;
    }
    return 0;
}
