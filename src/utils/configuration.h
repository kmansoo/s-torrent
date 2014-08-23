#ifndef CONFIG_GUARD
#define CONFIG_GUARD

#include <jsoncpp/json/json.h>
#include <memory>
#include <string>
#include "configuration_element.h"
#include "configuration_list_element.h"

namespace utils
{
    class Configuration_element;

    class Configuration
    {
        public:
            // Get root Configuration_element
            static std::shared_ptr < Configuration_element > get_root ();

            // Save and load from and to file
            static void save ();
            static void load ( std::string path );

            virtual ~Configuration () = default;

        private:
            Configuration ();

            static std::shared_ptr < Json::Value > json_value;
    };

}

#endif //CONFIG_GUARD
