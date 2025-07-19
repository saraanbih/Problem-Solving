public class Solution {
    public IList<string> RemoveSubfolders(string[] folder) {
        Array.Sort(folder);
        List<string> res = new List<string>();
        
        foreach(var f in folder){
            if(res.Count == 0 || !f.StartsWith(res[^1] + "/"))
                res.Add(f);
        }
        
        return res;
    }
}