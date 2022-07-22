#include<bits/stdc++.h>
using namespace std;

int* fun1(int x){
    return &x;
}

int* fun2(int x){
    int y = x;
    return &y;
}

int* fun3(int& x){
    return &x;
}

void generateRandNum(int n){
    
    for(int i =0;i<10;i++){
        srand( (unsigned)time(NULL) );
        cout<<  rand() % n << endl;
    }
}

//vector<string> 迭代器 test
void testVectorString(){
    vector<string> s = {"cat","bat","rat"};
    auto it = s.begin()+1;
    cout << *it << endl;
    while(it != s.begin()-1){
        cout << "2" << endl;
        --it;
    }
}

const int MOD = 1e9 + 7;

int computePower(long long A, int m){
    //快速幂求A的m次方
    long long ret = 1;
    while(m > 1){
        if(m % 2==0){
            A = A * A % MOD;
            m /= 2;
        }else{
            ret = ret * A % MOD;
            --m;
        }
    }
    ret = ret * A % MOD;
    return ret;
}

//从n个中拿m个
int computeC1(int n, int m, vector<int>& factorial){
    long long ret = 1;
    for(int i=1;i <= n;i++){
        ret = ret * i % MOD;
        factorial[i] = ret;
    }
    //求乘法逆元
    ret = ret * computePower(factorial[m], MOD-2) % MOD;
    ret = ret * computePower(factorial[n-m], MOD-2) % MOD;
    return ret;
}


int computeC2(int n, int m, vector<vector<int>>& c){
    if(n-m < m)
        m = n - m;
    if(c[n][m] != 0)
        return c[n][m];
    if(m == 1){
        c[n][m] = n;
    }else{
        long long ret = computeC2(n-1, m-1, c)+computeC2(n-1, m, c);
        c[n][m] = ret % MOD;
    }
    return c[n][m];
}

int count(int n, vector<int>& nums){
    int c = 0, maxC = 0;
    for(auto i:nums){
        if(i > n){
            ++c;
            maxC = max(c, maxC);
        }else
            c = 0;
    }
    return maxC;
}

int right(int a){
    return a>>2;
}


int main(){
    // cout<< generateRandNum(100) << endl;
    // generateRandNum(100);
    // testVectorString();
    // vector<int> factorial(101, 0);
    // cout << computeC1(100,25, factorial) << endl;
    // vector<vector<int>> c(101, vector<int>(101,0));
    // cout << computeC2(100, 25, c) << endl;
    // vector<int> nums = {5956,9692,1210,3175,8931,5396,9116,6425,8331,4883,3169,6578,9984,6330,1278,8987,1335,71,4922,3381,8991,3706,5279,325,1317,8708,3882,1410,8317,310,9180,1467,6945,422,113,365,7015,9142,6552,6970,8838,4767,7676,5580,4669,7824,258,7982,3091,3367,5119,1363,572,1026,5733,4074,1929,2850,4395,7073,1863,5340,6556,1046,1176,6225,9707,8243,4261,2584,3225,4641,8137,9517,6990,489,3039,9834,9369,2126,1840,7543,499,2438,4079,4508,1925,8125,1875,6822,1838,740,2631,9558,7316,2619,2155,9554,599,4252,9090,3753,3700,4439,4678,6463,7618,4970,3746,9175,7546,2964,3262,884,4009,9476,6602,2540,3600,277,8677,3729,306,4806,2053,9785,825,1077,5417,1249,1647,7224,2962,5220,6819,9192,3452,3198,8910,4568,878,5841,1638,2207,4032,7886,2907,6993,4218,7002,6336,4415,7286,1667,6081,8175,8389,4460,5719,2337,9364,8498,1840,5211,4498,2968,8901,1578,8655,3464,6762,7967,9177,8017,7104,8934,6802,3612,2931,3489,6384,992,5212,5373,3708,1455,311,4554,6140,4302,4609,8502,2614,217,1229,3790,1920,1949,7869,7724,9182,4256,7487,1200,2191,4521,5555,4809,6030,1446,6084,9734,3662,5169,8928,4387,1173,8711,7381,7352,7453,7105,5719,2430,3800,6171,7596,9734,3002,1550,646,325,5633,1482,1035,8500,6180,1565,5522,8374,8676,2453,1566,7113,6671,3586,176,2387,4630,7932,831,75,4357,5635,4496,3793,6884,6228,2203,4905,2530,5609,3904,3458,1000,9594,415,4858,228,5249,9022,1038,5263,9902,1261,9394,3773,7916,3417,2280,8290,6318,9683,6542,9604,5265,4745,6904,6705,7486,4118,283,3120,3592,8820,9114,6811,1130,1499,725,6311,3478,1024,4987,9287,5202,808,4414,4443,2341,7842,2355,3003,8171,6664,3168,7142,3692,4227,806,2344,561,6498,5425,5452,3549,7482,307,5408,7298,2642,1643,1699,2735,4629,4039,4943,6721,3563,8417,3166,5595,7827,149,5483,9224,3544,2079,6172,9624,1343,6237,789,9277,8912,3869,7825,6170,9952,4648,5845,4586,1529,4915,5680,9545,8909,8459,5360,1454,8220,1707,6874,6105,2770,3154,450,6854,9088,1535,9883,3803,8560,2591,2056,5755,2408,6560,5600,8314,9426,5972,3275,4398,6833,2272,5666,5731,7532,5746,3245,2085,791,2661,2351,7160,3251,7387,6651,8560,3081,1261,5280,9378,6665,2410,7976,1838,5957,7391,8302,3453,2632,6411,5632,7669,1904,5475,7906,2696,4972,7680,3215,7497,3523,7531,2765,9932,8973,5048,2196,7176,3570,4141,9479,1814,4479,4504,6962,8509,3526,5178,6773,7700,7126,148,3934,2134,5037,7326,8897,3003,5715,286,8656,4319,2902,7480,3139,1163,3059,2923,8194,4912,6161,8418,9914,5601,1307,276,6059,114,5078,6492,3642,670,6846,7548,2256,280,6340,6713,3722,378,3653,2016,4808,7838,438,1199,1993,6228,1451,8202,1548,4586,5176,183,8036,5674,2384,7124,3225,1044,2511,2856,7758,3749,4683,6680,740,8960,1992,5833,7579,3901,6944,3043,6158,4595,9422,808,930,2080,6303,6246,8609,2850,9940,9342,8665,2956,8199,6845,414,4017,9927,2433,3681,6403,6582,9001,3780,4621,6441,8326,3568,9981,8837,2586,7449,1984,4972,401,2965,9862,2861,1511,7077,9715,4694,8931,9678,3301,7941,4184,5939,4302,6646,1420,3817,6616,8717,4003,7468,926,4198,4688,9260,1779,7514,687,6059,3977,2181,30,8421,8792,1901,2848,4163,9275,3415,3246,8088,1223,816,9816,7445,4059,8821,2606,6464,6280,6969,7212,3839,4737,405,9303,5790,3334,6845,267,8397,2792,1299,8061,4643,5371,9197,4085,5998,2203,1904,6423,7594,5585,2663,777,9613,5057,2221,2112,6209,1938,5774,2818,2733,6906,6534,8277,877,4025,7708,1701,4411,4980,4307,9527,770,8475,7055,1242,9393,3169,766,7906,9490,8785,744,8505,7567,6483,2285,5038,8239,4975,2189,7425,9673,3395,8676,8110,7161,8696,3185,9160,1328,3467,488,7302,6262,2633,5820,3059,5769,7801,9304,3434,9116,1815,6547,205,1913,1825,3945,9925,4478,1622,7675,1988,1640,7847,9489,1040,7656,5126,5651,3825,213,7568,4134,3056,6458,523,2128,5610,9295,1669,2288,3243,9783,2848,2296,2417,5038,784,9098,653,1107,6061,8277,8784,8458,6640,5416,2804,5506,9364,393,7338,7380,413,8793,9140,5455,9320,6363,3561,1998,927,3488,1332,4452,9580,1372,9079,1116,39,4902,6674,2559,4657,6071,6842,5715,12,882,2256,5919,4813,7302,1499,6106,2091,7510,1367,7361,8007,1897,3945,4917,6698,500,8471,6610,9806,4484,2442,1458,9468,9472,2802,4685,2301,3595,9612,2993,5012,8388,3030,4389,3203,7432,7372,8436,1182,7305,7529,234,496,7332,6139,2831,5454,6207,9489,3267,3198,5747,9671,5706,9318,2781,4544,9868,3717,345,5231,9650,3855,6428,3154,8951,280,8356,8676,4677,8423,3359,4124,203,3962,9552,9230,829,1844,111,4380,9825,3972,8005,3134,2005,6225,1732,3806,8107,4747,4641,9197,5407,6842,9189,9380,4387,7912,1301,2987,3920,7538,3141,2872,2075,867,3570,3075,5613,6254,7248,2661,397,9086,2524,2564,557,5231,5941,6568,8759,6896,7053,1661,8530,7309,2642,3058,3849,4174,7278,5386,1372,8474,1127};
    // int res = count(6485, nums);
    //int res = right(-2);
    return 0;
}
