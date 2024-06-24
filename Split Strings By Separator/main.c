int my_strlen(char* ptr , int separator , int index){
    int i = index;
    int length = 0;
    while(ptr[i] != separator && ptr[i] != '\0'){
        length++;
        i++;
    }
    return length;
}
char** splitWordsBySeparator(char ** words, int wordsSize, char separator, int* returnSize){
    int bar = 0;
    for(int i = 0 ; i < wordsSize ; ++i){
        int j = 0;
        while(words[i][j]){
            if(words[i][j] != separator){
                ++bar;
                int word_length = my_strlen(words[i],separator,j);
                j += word_length;
            }else{
                j++;
            }
        }
    }
    *returnSize = bar;
    char** arr =(char**)malloc(sizeof(char*) * bar);
    if(!arr){exit(1);}
    int k = 0;
    for(int i = 0 ; i < wordsSize ; ++i){
        int j = 0;
        while (words[i][j]){
            if(words[i][j] != separator){
                int word_length = my_strlen(words[i] , separator,j);
                arr[k] = (char*)malloc(word_length + 1 * sizeof(int));
                if(!arr){exit(1);}
                for(int l = 0 ; l < word_length ; ++l){
                    arr[k][l] = words[i][j+l];
                }
                arr[k][word_length] = '\0';
                j += word_length;
                k++;
            }else{
                j++;
            }
        }
    }
    return arr;
}
