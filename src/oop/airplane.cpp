#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

enum seating {
  Premium,
  Business,
  Economy
};

class airline
{
public:
  virtual double calculatePrice(const double miles, const seating seat) = 0;
  double operatingCost(const double miles, const seating seat)
  {
    if (seat == Premium)
      return 0.1 * miles;
    else if (seat == Business)
      return 50;
    return 0;
  }
};

class united : public airline
{
public:
  double calculatePrice(const double miles, const seating seat)
  {
    double ans = 0;
    ans += miles * 0.75;
    ans += operatingCost(miles, seat);
    return ans;
  }
};

class delta : public airline
{
public:
  double calculatePrice(const double miles, const seating seat)
  {
    double ans = 0;
    ans = std::max(10.0, operatingCost(miles, seat));
    return ans;
  }
};

double cost(airline *airline, double miles, seating seat)
{
  return airline->calculatePrice(miles, seat);
}

std::vector<std::vector<std::string>> input = { { "united", "500.0", "Premium" }, { "delta", "800.0", "Business" } };
int main()
{
  std::unordered_map<std::string, airline *> m;
  m["united"] = new united();
  m["delta"] = new delta();
  std::unordered_map<std::string, int> seat_map;
  seat_map["Premium"] = 0;
  seat_map["Business"] = 1;
  seat_map["Economy"] = 2;
  for (auto in : input) {
    double miles = stod(in[1]);
    seating seat = seating(seat_map[in[2]]);
    std::cout << in[0] << " cost: " << cost(m[in[0]], miles, seat) << std::endl;
  }
  return 0;
}