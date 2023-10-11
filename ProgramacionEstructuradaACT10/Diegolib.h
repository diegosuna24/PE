

int num_ent_pos(int num){
    if (num<0||num%1==!0){
        return 0;
    }
    else
    {
        return 1;
    }
}

int no_rep(int vector[],int largovector,int num){
    int ban=1;
    for(int i=0;i<=largovector;i++){
        if(vector[i]==num)
        {
            ban=0;
        }
    }
    if(ban==0){
        return 0;
    }
    else{
        return 1;
    }
}

