main() 
{ 
    char filename[]="case1.in";
    char tmp_w[21];

    FILE * infile;
    infile=open(filename);

    while(next(infile,tmp_w))
        if(strlen(tmp_w)>0)
            counter(tmp_w);

    sortk_v();
    output();
} 