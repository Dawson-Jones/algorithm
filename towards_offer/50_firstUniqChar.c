char firstUniqChar(char* s){
    int len=strlen(s);
    if(len==0)
        return ' ';
    if(len==1)
        return s[0];
    int map[26];
    memset(map, 0, sizeof(map));

    for(int i=0;i<len;i++)
        map[s[i]-'a']++;
    for(int i=0;i<len;i++)
        if(map[s[i]-'a']==1)
            return s[i];
    return ' ';
}