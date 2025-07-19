// THE IDEA IS IF WE HAVE TO DOUBLE THE ORIGINAL STRING AND WE WILL FIND IT AND .FIND() IN STRING RETURN INDEX AND IF NOT FOUNF THEN IT RETURNS string::npos
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size())return false;
        if (goal == s)
            return true;
        string searcha = s + s;
        if (searcha.find(goal) == string::npos)
            return false;
        return true;
    }
};
