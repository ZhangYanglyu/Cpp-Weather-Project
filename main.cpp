#include <iostream>
#include <string>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

size_t getUrlReponse(char *buffer, size_t size, size_t count, std::string *response)
{
    size_t recv_size = size * count;

    response->append(buffer,0, recv_size);

    return recv_size;
}

int main(int, char**) 
{
    curl_global_init(CURL_GLOBAL_DEFAULT);

    std::string response;

    CURL *handle = curl_easy_init();

    //todo 1: set url
    std::string url{"api.seniverse.com/v3/weather/now.json?key=SUZ0u6Z97TnJ-7SFf&location=beijing&language=en&unit=c"};
    curl_easy_setopt(handle, CURLOPT_URL, url.c_str());

    // //todo 2: callback function
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, getUrlReponse);

    //todo 3: set stream
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);

    //todo 4: perform Get command
    curl_easy_perform(handle);

    std::cout << response << std::endl;

    //todo : Json decode

    //todo 5: 
    curl_easy_cleanup(handle);

    //todo 6:
    curl_global_cleanup();

    return 0;
}
