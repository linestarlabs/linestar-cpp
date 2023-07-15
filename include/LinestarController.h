#pragma once

#include <pistache/http.h>
#include <pistache/router.h>
#include "Linestar.h"

class LinestarController {
public:
    void handleWake(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);
    void handleMoveToHome(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);
    void handleGoToPosition(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);
    void handleReportLocation(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);
    void handleReportErrorMargin(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);

private:
    Linestar linestar;
};

