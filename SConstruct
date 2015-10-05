env = Environment(
    CCFLAGS = '-Wall',
    LINKFLAGS = "-lpq -arch x86_64",
    CPPPATH = ['/usr/local/include/'],
    LIBPATH = ['/usr/local/lib'],
    CXXFLAGS="-std=c++11")

main_sources = [
    'src/RedshiftConnector.hh',
    'src/runner.cc']

test_sources = [
  'src/Building.hh',
  'test/BuildingTest.hh']

env.Program('main', ['src/runner.cc'])
