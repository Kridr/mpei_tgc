//https://leetcode.com/problems/defanging-an-ip-address/
class Solution {
public:
    string defangIPaddr(string address) {
        vector <char> dip;

        for (int i = 0; i < address.length(); i++)
            if (address[i] != '.') {
                dip.push_back(address[i]);
            } else {
                dip.push_back('[');
                dip.push_back('.');
                dip.push_back(']');
            }
        return string(dip.begin(), dip.end());

    }
};
