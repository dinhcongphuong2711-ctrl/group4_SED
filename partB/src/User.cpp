#include <string>
using namespace std;

class User
{
private:
    string username;
    string role; // admin / operator

public:
    User(string u = "guest", string r = "operator")
    {
        username = u;
        role = r;
    }

    string getName() const { return username; }
    string getRole() const { return role; }
};
