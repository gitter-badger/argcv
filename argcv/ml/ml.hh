#ifndef ARGCV_ML_ML_HH
#define ARGCV_ML_ML_HH

// Machine learning is a subfield of computer science that evolved from
// the study of pattern recognition and computational learning theory in
// Artificial Intelligence. Machine learning explores the construction and
// study of algorithms that can learn from and make predictions on data.
// ref: http://en.wikipedia.org/wiki/Machine_learning

#include <stdint.h>  // uint64_t

#include <string>
#include <vector>
#include <utility>  // std::pair, std::make_pair

namespace argcv {
namespace ml {

// dataset_d ds;
// double x1[] = {0.1,0.2,0.3,1.4,1.5};
// double x0[] = {-0.1,-0.2,-0.3,-1.4,-1.5};
// ds.add(x1,5,1);
// ds.add(x0,5,0);
// printf("%f => %d - %f => %d
// \n",ds.x_at(0,1),ds.y_at(0),ds.x_at(1,1),ds.y_at(0));

template <typename X, typename Y>
class dataset {
public:
    dataset() {}
    std::vector<std::pair<std::vector<X>, Y>> data() { return ds; }
    virtual ~dataset() {}
    const uint64_t size() const { return ds.size(); }
    std::pair<std::vector<X>, Y> &operator[](uint64_t pos) { return ds[pos]; }
    std::pair<std::vector<X>, Y> &at(uint64_t pos) { return ds.at(pos); }
    std::vector<X> &x_at(uint64_t pos) { return at(pos).first; }
    X &x_at(uint64_t pos, uint64_t off) { return x_at(pos).at(off); }
    Y &y_at(uint64_t pos) { return at(pos).second; }
    void add(std::pair<std::vector<X>, Y> ds_item) { return ds.push_back(ds_item); }
    void add(std::vector<X> x, Y y) {
        std::pair<std::vector<X>, Y> val(x, y);
        return ds.push_back(val);
    }
    void add(X x[], int len, Y y) {
        std::pair<std::vector<X>, Y> val(std::vector<X>(x, x + len), y);
        return ds.push_back(val);
    }
    void rm(uint64_t pos) { ds.erase(ds.begin() + pos); }
    void rm() { ds.clear(); }
    void del(uint64_t pos) { rm(pos); }
    void del() { rm(); }
    void clear() { rm(); }

private:
    std::vector<std::pair<std::vector<X>, Y>> ds;
    std::vector<std::vector<int>> v;
};

typedef dataset<double, int> dataset_d;
typedef dataset<double, bool> dataset_db;
typedef dataset<double, double> dataset_dd;
typedef dataset<std::string, int> dataset_s;
typedef dataset<std::string, bool> dataset_sb;
typedef dataset<std::string, std::string> dataset_ss;
}
}  // namespace argcv::ml

#endif  //  ARGCV_ML_ML_HH
