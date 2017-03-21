float compoe(int inteiro,int fracionario){
    float saida=1.0*inteiro,termo=1.0*fracionario;
    while(termo>1.0){
        termo=termo*0.1;
    }
    saida=saida+termo;
    return saida;
}
