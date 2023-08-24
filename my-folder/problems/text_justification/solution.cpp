class Solution {
public:
    string solve(vector<string>& words,int space,int rightMost,int i,int j)
    {

        string temp = "";

        temp += words[i++];
        while(i<j)
        {
            int s = space;

            while(s--)
            {
                temp.push_back(' ');
            }

            if(rightMost-->0)
            {
                //rightMost--;
                temp.push_back(' '); 
            }

            temp += words[i++];
        }
        return temp;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        int j=0;

        vector<string> ans;

        int size = words.size();

        while(j<size)
        {
            int width = words[j++].size();

            while(width<=maxWidth)
            {
                if(j>=size) 
                    break;
                width += 1 + words[j++].size();
            }
            if(width > maxWidth)
                j--;
            if(j>=size) 
                break;
            width = width - 1 - words[j].size() - (j-i-1);
            int space  = 0;
            int rightMost = 0;
            if(j-i-1 != 0)
                space = (maxWidth - width)/(j-i-1);
            if(j-i-1 != 0)
                rightMost = (maxWidth - width) - (j-i-1)*space;

            string temp = solve(words,space,rightMost,i,j);

            while(temp.size()<maxWidth)
            {
                temp.push_back(' ');
            }

            ans.push_back(temp);

            i = j;
        }

        string temp ="";

        while(i<size)
        {
            temp += words[i++];
            temp.push_back(' ');
        }
        temp.pop_back();
        while(temp.size()<maxWidth)
        {
            temp.push_back(' ');
        }

        ans.push_back(temp);

        return ans;
        
    }
};