env = Environment()

test_sources = [
  'src/Building.hh',
  'test/BuildingTest.hh']

env.Program(target = 'dist/whatever', source = 'src/Building.hh')
env.Program(target = 'dist/sure', source = 'src/CityBuilder.hh')
env.Program(target = 'dist/test-suite', source = test_sources)
