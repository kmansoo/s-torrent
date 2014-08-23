#ifndef HUB_GUARD
#define HUB_GUARD

#include <memory>
#include <string>
#include <map>
#include "event_types/event.h"
#include "filter_node.hpp"
#include "broadcaster.hpp"

namespace events
{
    class Hub
    {
        public:
            // Create a filter that filters via regex on Event::get_type
            static void create_filter ( std::string identifier, std::string regex );
            static Filter_node < std::shared_ptr < Event > >& get_filter ( std::string identifier );
            // Send event
            static void send ( std::shared_ptr < Event > event );

        private:
            Hub () = default;

            static std::map < std::string, std::shared_ptr < Filter_node < std::shared_ptr < Event > > > > filters;
            static Broadcaster < std::shared_ptr < Event > > broadcaster;
    };
}

#endif //HUB_GUARD
