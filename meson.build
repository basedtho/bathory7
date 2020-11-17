project('bathory7', 'cpp', default_options : ['cpp_std=c++17'])
dep = [dependency('SDL2')]
dep += [dependency('SDL2_image')]
dep += [dependency('fmt')]
incdir = [include_directories('include')]
executable('bathory7',
           'src/main.cpp',
           'src/game.cpp',
           'src/texture_manager.cpp',
           'src/game_object.cpp',
           'src/map.cpp',
           dependencies : dep,
           include_directories : incdir)
