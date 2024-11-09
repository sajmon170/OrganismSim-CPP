project('simulator', 'cpp')

subdir('src')
subdir('src/plants')
subdir('src/animals')

inc = include_directories('include', 'include/animals', 'include/plants')

libcursespp_proj = subproject('libcursespp')
libcursespp_dep = libcursespp_proj.get_variable('libcursespp_dep')
curses_dep = libcursespp_proj.get_variable('curses_dep')

executable('simulator',
  sources,
  include_directories : inc,
  dependencies : [libcursespp_dep, curses_dep],
  install: true)
