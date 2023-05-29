#include <iostream>
#include <string>
#include <map>

using namespace std;

int main ()
{
  std::map<string,int> mymap;

  mymap["betty"] = 100;
  mymap["arnold"] = 200;
  mymap["dodo"] = 300;

  // show content:
  for (std::map<string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}