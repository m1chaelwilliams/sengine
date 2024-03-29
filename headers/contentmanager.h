#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <map>
#include <string>
#include "textureutils.h"

namespace se::managers {
    class ContentManager {
        public:
            ContentManager() {}
            ~ContentManager();

            SDL_Texture* load_texture(
                SDL_Renderer* renderer_ptr, 
                const char* filename, 
                const char* name = ""
            );
            SDL_Texture* load_texture(
                SDL_Renderer* renderer_ptr, 
                SDL_Surface* surf, 
                const char* filename,
                bool free_surf = false
            );
            se::TextureData load_texture_data(
                SDL_Renderer* renderer_ptr, 
                const char* filename,
                const char* name = ""
            );
            
            SDL_Texture* get_texture(const char* key);
            SDL_Rect get_rect(const char* filename);

            // fonts
            TTF_Font* load_font(const char* filename, int size, const char* name = "");
            TTF_Font* get_font(const char* name);

            // audio
            Mix_Music* load_music(const char* filename, const char* name);
            Mix_Music* get_music(const char* name);
            
            Mix_Chunk* load_sound_fx(const char* filename, const char* name);
            Mix_Chunk* get_sound_fx(const char* name);

            void free_all();
        private:
            std::map<std::string, SDL_Texture*> textures;
            std::map<std::string, TTF_Font*> fonts;
            std::map<std::string, Mix_Music*> music;
            std::map<std::string, Mix_Chunk*> sound_fx;
    };
}

#endif