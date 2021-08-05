int solution(int cacheSize, vector<string> cities)
{
    if (cacheSize == 0) return cities.size() * 5;
    for(int i = 0;i<cities.size();i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), :: tolower);
    }
    list<string> cache;
    int answer = 0;
    
    for (int i = 0; i < cities.size(); i++)
    {
        string nName = cities[i];
        bool F = 0;
        list<string>::iterator it = cache.begin();
        for (it; it != cache.end(); it++)
        {
            if (*it == nName)
            {
                F = 1;
                answer = answer + 1;
                cache.erase(it);
                cache.push_back(nName);
                break;
            }
        }
 
        if (F == 0)
        {
            answer = answer + 5;
            if (cache.size() == cacheSize)
            {
                cache.pop_front();
                cache.push_back(nName);
            }
            else cache.push_back(nName);
        }
    }
    return answer;
  }
