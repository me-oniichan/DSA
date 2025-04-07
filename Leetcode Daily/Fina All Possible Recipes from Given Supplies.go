func findAllRecipes(recipes []string, ingredients [][]string, supplies []string) []string {
    suppMap:=make(map[string]bool)
    for i:=0;i<len(supplies); i++ {
        suppMap[supplies[i]]=true
    }
    recIndex:=make(map[string]int)
    for i:=0; i <len(recipes); i++{
        recIndex[recipes[i]]=i
    }
    for i:=0; i <len(recipes); i++{
        samePath:=make(map[string]bool)
        if suppMap[recipes[i]] || len(ingredients)==0{
            continue
        }
        dfs(i,recipes,ingredients,suppMap,samePath,recIndex)
    }
    result:=[]string{}
     for i:=0; i <len(recipes); i++{
        if suppMap[recipes[i]] {
            result=append(result,recipes[i])
        }
    }
    return result
}

func dfs(i int,recipes []string, ing [][]string, suppMap,samePath map[string]bool,recIndex map[string]int) bool{
    if samePath[recipes[i]] {
        return false
    }
    if suppMap[recipes[i]] {
        return true
    }
    samePath[recipes[i]]=true
    //suppMap[recipes[i]]=true

    for _,rec:=range ing[i] {
        if suppMap[rec] {
            continue
        }
        index,ok:=recIndex[rec]; 
        if !ok {
            return false
        }
        if !dfs(index,recipes,ing,suppMap,samePath,recIndex){
            return false
        }
    } 
    samePath[recipes[i]]=false
    suppMap[recipes[i]]=true
    return true
}
