#include "Server.h"

using namespace simple_http_server;

int main() {
  Server server;

  server.MapUrl("/solve", [](const Server::Request&){
    // mock up response
    return Server::CreateResponse(200,
                                  R"([{"id":11,"from":{"x":2,"y":3},"to":{"x":2,"y":2}},)"
                                  R"({"id":15,"from":{"x":3,"y":3},"to":{"x":2,"y":3}}])",
                                  "",
                                  {{"Access-Control-Allow-Origin", "*"}});
  });

  server.Start("0.0.0.0", 8080);

  return 0;
}
