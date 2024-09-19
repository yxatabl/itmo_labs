#include <iostream>
#include <vector>
#define SIZE 50021
using namespace std;

template <typename T>
class hashMap{
    struct data{
        int x = -1;
        T f;
    };

    data mas[SIZE];

    int hashFunc(int num){
        return num%SIZE;
    }

    public:
    T& operator [](int x){
        int h = hashFunc(x);
        while (mas[h%SIZE].x != x && mas[h%SIZE].x != -1) h++;
        mas[h%SIZE].x = x;
        return mas[h%SIZE].f;
    }
};

hashMap<int> mapX, mapY;

class resultLines{
    struct line{
        bool tcord = 0;
        int cord = -1;
        int length = -1;
    };

    line lines[4];
    hashMap<vector<int>> pointsByX;

    void addLine(bool t, int cord){
        bool exists = false;
        for (int i = 0; i < 4; i++){
            if ((lines[i].tcord == t) && (lines[i].cord == cord)){
                exists = true;
                lines[i].length++;
                break;
            }
        }

        if (!exists){
            int length;
            
            if (t == 0) length = mapX[cord];
            else length = mapY[cord];

            lines[3] = {t, cord, length};
        }

        for (int i = 0; i < 3; i++){
            for (int j = 2; j >= i; j--){
                if (lines[j].length < lines[j+1].length) swap(lines[j], lines[j+1]);
            }
        }
    }

    int crossingPoints(){
        int count = 0;
        for (int i = 0; i < 2; i++){
            for (int j = i+1; j < 3; j++){
                if (lines[i].tcord != lines[j].tcord){
                    int x, y;
                    if (lines[i].tcord){
                        y = lines[i].cord;
                        x = lines[j].cord;
                    } else {
                        y = lines[j].cord;
                        x = lines[i].cord;
                    }
                    bool exists = false;
                    for (int el : pointsByX[x]) if (el == y){
                        exists = true;
                        break;
                    }
                    exists ? count++ : 0;
                }
            }
        }

        return count;
    }

    public:
    void addPoint(int x, int y){
        addLine(0, x);
        addLine(1, y);
        pointsByX[x].push_back(y);
    }

    int getResult(){
        return lines[0].length+lines[1].length+lines[2].length-crossingPoints();
    }
};

int main(){
    int n;
    cin >> n;
    resultLines res;
    
    int minLength = 0;
    for (int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        mapX[x]++;
        mapY[y]++;
        res.addPoint(x, y);
    }

    res.getResult() >= n ? cout << "YES" : cout << "NO";
}