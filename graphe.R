rm(list=ls())

d=read.table("VFsMmoy.txt",col.names=c("T","Ainit","Etat"),header=T)

colfunc<-colorRampPalette(c("red","yellow"))
etat <- factor(d$"Etat")
mescouleurs <- colfunc(length(levels(etat)))# Gradient
#mescouleurs <- rainbow(length(levels(etat)))
plot(d$"T", d$"Ainit", pch = 19,col = mescouleurs[etat], main="Diagramme Transition Sans Mutation",xlab="T",ylab="Ainit")
legend("topright", inset = 0.01, pch = 19, legend = c("extinction","exclusion","cohabitation"), col = mescouleurs)

#_ _ _ _ _ _ _

dmut=read.table("VFaMmoy.txt",col.names=c("T","Ainit","Etat"),header=T)

etat <- factor(dmut$"Etat")
mescouleurs <- rainbow(length(levels(etat)))
plot(dmut$"T", dmut$"Ainit", pch = 19, col = mescouleurs[etat], main="Diagramme Transition Avec Mutation",xlab="T",ylab="Ainit")
legend("topright", inset = 0.02, pch = 19, legend = c("extinction","cohabitation"), col = mescouleurs)

