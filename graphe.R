rm(list=ls())

d=read.table("VFmut.txt",col.names=c("T","Ainit","Etat"),header=T)

etat <- factor(d$"Etat")
mescouleurs <- rainbow(length(levels(etat)))
plot(d$"T", d$"Ainit", pch = 19, col = mescouleurs[etat], main="Diagramme Transition Sans Mutation")
legend("topright", inset = 0.02, pch = 19, legend = c("extinction","exclusion","cohabitation"), col = mescouleurs)

#_ _ _ _ _ _ _


dmut=read.table("VFmut.txt",col.names=c("T","Ainit","Etat"),header=T)

etat <- factor(dmut$"Etat")
mescouleurs <- rainbow(length(levels(etat)))
plot(dmut$"T", dmut$"Ainit", pch = 19, col = mescouleurs[etat])
legend("topright", inset = 0.02, pch = 19, legend = c("extinction","cohabitation"), col = mescouleurs)
