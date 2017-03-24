int menor_de_tres(int x,int y,int z){
    int saida;
    if(x<=y){
        if(x<=z) saida=x;
        else saida=z;
    }
    else{
        if(y<=z) saida=y;
        else saida=z;
    }
    return saida;
}

int menor_de_tres_v2(int x,int y,int z){
    return x*(x<=y&&x<=z)+y*(x>y&&y<=z)+z*(x>y&&y>z);
}
