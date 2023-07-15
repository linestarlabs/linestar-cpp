
#include "LinestarController.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

void LinestarController::handleWake(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response) {
    linestar.wake();
    response.send(Pistache::Http::Code::Ok, "System woke up successfully");
}

void LinestarController::handleMoveToHome(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response) {
    linestar.moveToHome();
    response.send(Pistache::Http::Code::Ok, "Moved to home position successfully");
}

void LinestarController::handleGoToPosition(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response) {
    try {
        const auto body = request.body();
        const auto data = json::parse(body);

        const auto x = data["x"].get<float>();
        const auto y = data["y"].get<float>();

        linestar.goToPosition(x, y);
        response.send(Pistache::Http::Code::Ok, "Moved to position successfully");
    } catch (const json::exception& e) {
        response.send(Pistache::Http::Code::Bad_Request, "Invalid JSON payload");
    } catch (const std::exception& e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }
}

void LinestarController::handleReportLocation(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response) {
    const auto location = linestar.reportLocation();
    json data = {
        {"location", location}
    };
    response.send(Pistache::Http::Code::Ok, data.dump());
}

void LinestarController::handleReportErrorMargin(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response) {
    const auto error_margin = linestar.reportErrorMargin();
    json data = {
        {"error_margin", error_margin}
    };
    response.send(Pistache::Http::Code::Ok, data.dump());
}


