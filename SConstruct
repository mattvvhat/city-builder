
env = Environment(
    CCFLAGS = '-Wall',
    LINKFLAGS = "-lpq -arch x86_64",
    CPPPATH = ['/usr/local/include/'],
    LIBPATH = ['/usr/local/lib']
    )

test_sources = [
  'src/Building.hh',
  'test/BuildingTest.hh']

env.Program(
    target = 'main',
    source = 'src/runner.cc')

# env.Program(target = 'dist/whatever', source = 'src/Building.hh')
# env.Program(target = 'dist/sure', source = 'src/CityBuilder.hh')
# env.Program(target = 'dist/test-suite', source = test_sources)
