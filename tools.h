Mat readMat(int n= -1, int m =  -1){
    if(n == -1 && m  == -1) // 默认需要用户输入行数和列数
    {
        do{
    cout << "请输入行数和列数，中间以空格分割：";
    int n, m;cin >> n >> m;
    }while(cin.fail());
    }


    cout<<"请输入一个" << n "行 " << m "列的矩阵, 数字直接以空格分割: \n";
    Mat matrix;
    matrix.n =  n;matrix.m =m;
    for(int i = 0;i<a.n;i++){
        for(int j = 0;j<a.m;j++){
            cin >> matrix.value[i][j];
        }
    }
    return Mat;
}

void showMat(mat a){
    for(int i = 0;i<a.n;i++){
        for(int j = 0;j<a.m;j++){
            cout << a.value[i][j];
        }
    }
}

Mat matriplus(){
    cout << "欢迎使用矩阵相加功能！\n ";
    cout << "请输入第一个矩阵：\n"
    Mat mat1 = readMat();
    cout << "请输入第二个矩阵：\n"
    Mat mat2 = readMat(mat1.n,mat1.m);
    Mat res_mat;
    res_mat.n = mat1.n; 
    res_mat.m = mat1.m; 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            res_mat.value[i][j] = mat1.value[i][j] + mat2.value[i][j];
        }
    }
    return res_mat;
}

Mat nummulti(){
    cout << "欢迎使用矩阵数乘功能！\n ";
    cout << "请输入一个实数：";
    double k;cin>>k;
    cout << "请输入矩阵：\n";
    Mat a = readMat();
    for(int i = 0;i<a.n;i++){
        for(int j = 0;j<a.m;j++){
            a.value[i][j] *= k;
        }
    }
    return a;
}

