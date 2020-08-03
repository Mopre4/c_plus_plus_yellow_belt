#include "iostream"
#include "numeric"

using namespace std;
 // объем = W*D*H
int main(){
    int N, R;
    uint64_t w, d, h;
    uint64_t summ = 0;
    cin >> N >> R;
    for (size_t i = 0; i < N; i++){
        cin >> w >> d >> h;
        summ += (w*d*h)*R;

    }
    cout << summ;
    return 0;
}