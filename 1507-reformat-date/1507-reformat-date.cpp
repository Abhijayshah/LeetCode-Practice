class Solution {
public:
    string reformatDate(string date) {
            unordered_map<string, string> months{{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        string ans{};
        int len = date.length();
        ans += date.substr(len-4, 4);
        ans += "-";
        ans += months[date.substr(len-8, 3)];
        ans += "-";
        if(date[1] >= 'a' && date[1] <= 'z')
        {
            ans += "0";
            ans += date[0];
        }
        else
        {
            ans += date.substr(0, 2);
        }

        return ans;
    }
};