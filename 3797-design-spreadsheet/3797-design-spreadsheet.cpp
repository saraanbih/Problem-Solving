class Spreadsheet {
public:
    vector<vector<int>> spread_sheet;
    Spreadsheet(int rows) {
        spread_sheet.resize(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int c = cell[0] - 'A';
        int r = stoi(cell.substr(1,cell.size())) - 1;
        spread_sheet[r][c] = value;
    }
    
    void resetCell(string cell) {
        int c = cell[0] - 'A';
        int r = stoi(cell.substr(1,cell.size())) - 1;
        spread_sheet[r][c] = 0;
    }
    
    int getValue(string formula) {
        auto pos = formula.find('+');
        string first = formula.substr(1,pos);
        string second = formula.substr(pos+1,formula.size());

        int ans = 0;
        
        if(first[0] >= 'A' && first[0] <= 'Z'){
            int c = first[0] - 'A';
            int r = stoi(first.substr(1,first.size())) - 1;
            ans+=spread_sheet[r][c];
        }
        else
            ans += stoi(first);
        
        if(second[0] >= 'A' && second[0] <= 'Z'){
            int c = second[0] - 'A';
            int r = stoi(second.substr(1,second.size())) - 1;
            ans+=spread_sheet[r][c];
        }
        else
            ans += stoi(second);
        
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */