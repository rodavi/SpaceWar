#include "SFML/Graphics.hpp"
#include <memory>
#include <cassert>

namespace Textures
{
    enum ID {Landscape, Airplane, Enemy};
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
    std::map<Identifier, 
             std::unique_ptr<Resource>> mResourceMap;

    public:
                            ResourceHolder();
        void                load(Identifier id, const std::string& filename);
        template<typename Parameter>
        void                load(Identifier id, const std::string& filename, const Parameter& secondParam);
        Resource&           get(Identifier id);
        const Resource&     get(Identifier id) const;

};