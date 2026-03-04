class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin=celsius+273.15;
        double Fahrenheit=(celsius*1.80)+32.00;
        vector<double> solution;
        solution.push_back(kelvin);
        solution.push_back(Fahrenheit);
        return solution;
    }
};