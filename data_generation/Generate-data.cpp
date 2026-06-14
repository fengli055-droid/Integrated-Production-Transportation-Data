#include <iostream>
#include<cstdlib>
#include<ctime>
#include <random>
#include <vector>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <string>

#define random(a,b) (rand()%(b-a+1)+a) // random number from [a,b]

using namespace std;

void gen_alg3()
{
    //float rho = 1.1;
    vector<int> m_set = { 5,10,15 };
    vector<int> n_set = { 20, 40, 60, 80, 100 };
    vector<int> E = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> reject_set = { 1,2 };
    int q_max;
    //int random_instance_num = 30;

    //srand((unsigned)time(nullptr));

    int instance_num = 0;
    //for (auto iter_re : reject_set) 
    //{
        for (auto iter_m : m_set)
        {
            for (auto iter_n : n_set)
            {
                for (int n = 0; n < 10; ++n)
                {
                    instance_num++;
                    srand(instance_num);
                    q_max = 0;
                    vector<int> quantity_out, due_out;
                    for (int i = 0; i < iter_n; ++i)
                    {
                        int random = random(0, E.size() - 1);
                        quantity_out.push_back(E[random]);
                        if (E[random] > q_max)q_max = E[random];
                        int random_due = random(1, iter_m);
                        due_out.push_back(random_due);
                    }

                    int c_min = 0;
                    int c = 0;
                    for (int t = 1; t <= iter_m; ++t)
                    {
                        int sum_q = 0;
                        for (int i = 0; i < iter_n; ++i)
                        {
                            if (due_out[i] <= t)
                                sum_q += quantity_out[i];
                        }
                        int c_min_curr = ceil(double(sum_q) / double(t));
                        c_min = max(c_min, c_min_curr);
                    }
                    //if (iter_re == 1) {//without reject
                    //    int c_max = ceil(1.1 * double(c_min));
                    //    c = random(c_min, c_max);//生成daily capacity
                     //   c = max(c, q_max);
                    //}
                    //if (iter_re == 2) {//with reject
                        //int c_max = ceil(1.1 * double(c_min));
                        //int c = ceil(double(random(90, 100)/100.0)*double(c_min));//生成daily capacity
                        c = random(int(ceil(0.9 * c_min)), int(ceil(double(c_min))));
                        c = max(c, q_max);
                    //}
                    int beta = random(1, 5);
                    int alpha = random((iter_m - 1) * beta + 1, 2 * (iter_m - 1) * beta);
                    //int h = ceil(rho * beta);//**********与论文不符***********
                    int h = random(int(ceil(0.5 * beta)), int(floor(double(beta))));
                    vector<int>reject_cost;
                    for (int i = 0; i < iter_n; ++i)
                    {
                        int temp_a = random(alpha, 2 * alpha);
                        reject_cost.push_back((temp_a + h) * quantity_out[i]);
                    }
                    
                    string file_dir = "Instance_";

                    
                    file_dir += to_string(instance_num);
                    file_dir += ".txt";

                    ofstream new_outstuf(file_dir, ios::trunc);

                    new_outstuf << iter_m << endl;
                    new_outstuf << iter_n << endl;

                    for (int i = 0; i < quantity_out.size(); ++i)
                        if (i < quantity_out.size() - 1)
                            new_outstuf << quantity_out[i] <<'\t';
                        else new_outstuf << quantity_out[i];
                    new_outstuf << endl;

                    for (int i = 0; i < due_out.size(); ++i)
                        if (i < due_out.size() - 1)
                            new_outstuf << due_out[i] <<'\t';
                        else new_outstuf << due_out[i];
                    new_outstuf << endl;

                    for (int i = 0; i < reject_cost.size(); ++i)
                        if (i < reject_cost.size() - 1)
                            new_outstuf << reject_cost[i] <<'\t';
                        else new_outstuf << reject_cost[i];//r_i
                    new_outstuf << endl;

                    new_outstuf << c << endl;
                    new_outstuf << alpha << endl;
                    new_outstuf << beta << endl;
                    new_outstuf << h << endl;

                    

                    new_outstuf.close();
                }
            }
        }
  //  }
    
}

int main()
{
    //gen_alg1();
    //gen_alg2();
    gen_alg3();

    return 0;
}
