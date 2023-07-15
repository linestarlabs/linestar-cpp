#include <pistache/endpoint.h>
#include "LinestarController.h"

int main() {
    Pistache::Address address(Pistache::Ipv4::any(), Pistache::Port(9080));
    Pistache::Http::Endpoint endpoint(address);

    endpoint.init();

    LinestarController controller;
    Pistache::Rest::Routes::Post(
        "/wake",
        Pistache::Rest::Routes::bind(&LinestarController::handleWake, &controller)
    );
    Pistache::Rest::Routes::Post(
        "/move_to_home",
        Pistache::Rest::Routes::bind(&LinestarController::handleMoveToHome, &controller)
    );
    Pistache::Rest::Routes::Post(
        "/go_to_position",
        Pistache::Rest::Routes::bind(&LinestarController::handleGoToPosition, &controller)
    );
    Pistache::Rest::Routes::Get(
        "/report_location",
        Pistache::Rest::Routes::bind(&LinestarController::handleReportLocation, &controller)
    );
    Pistache::Rest::Routes::Get(
        "/report_error_margin",
        Pistache::Rest::Routes::bind(&LinestarController::handleReportErrorMargin, &controller)
    );

    endpoint.setHandler(Pistache::Rest::Router::create());

    endpoint.serveThreaded();

    endpoint.shutdown();
}

