//https://leetcode.com/problems/employee-importance/
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> map;

        for (const auto elem : employees)
            map[elem -> id] = elem;

        return help(map, id);
    }

    int help(unordered_map <int, Employee*>& map, int id) {
        auto sum = map[id] -> importance;

        for (const auto elem: map[id] -> subordinates)
            sum += help(map, elem);

        return sum;
    }
};
