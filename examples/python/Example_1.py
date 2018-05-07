import dsl

pmd = dsl.PluginMetaData("test", "myCategory")

print(pmd.getAll())
print (pmd.getPluginName())
pmd.setAuthor("Monty")

print (pmd.getAuthor())

