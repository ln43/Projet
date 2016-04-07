rm(list=ls())

library(rgl)

#Données
d=rbind(read.table("VFsMD.txt",col.names=c("T","Ainit","D","Etat"),header=T))

X=log10(as.numeric(levels(factor(d$"D"))))
X=c(c(0),X[2:length(X)])

d=data.frame(d$"T"[d$"D"!=0],d$"Ainit"[d$"D"!=0],d$"D"[d$"D"!=0],d$"Etat"[d$"D"!=0])
names(d)=c("T","Ainit","D","Etat") #d sans 0
X=log10(as.numeric(levels(factor(d$"D"))))

#View 1
etat <- factor(d$"Etat")
mescouleurs <- rainbow(length(levels(etat)))
plot3d(d$"T", d$"Ainit", log10(as.numeric(d$"D")), pch = 24, cex=1,col = mescouleurs[etat],xlab="T",ylab="Ainit",zlab="D")
legend("topright", inset = 0.02, pch = 19, legend = levels(etat), col = mescouleurs)

#View 2
par(mfrow=c(3,3))

for(i in levels(factor(d$"D"))){
  etat <- factor(d$"Etat"[d$"D"==i])
  mescouleurs <- c(2,3,4)
  plot(d$"T"[d$"D"==i], d$"Ainit"[d$"D"==i], pch = 19, col = mescouleurs[etat], main=paste("D = ",i),xlab="T",ylab="Ainit")
}
plot(1, type="n", axes=F, xlab="", ylab="",main="Transition de phase \n sans mutation")
legend("center", inset = 0.02, pch = 19, legend = levels(etat), col = mescouleurs)

#1 graphe
i=1e-1
etat <- factor(d$"Etat"[d$"D"==i])
mescouleurs <- c(2,3,4)
plot(d$"T"[d$"D"==i], d$"Ainit"[d$"D"==i], pch = 19, col = mescouleurs[etat], main=paste("D = ",i),xlab="T",ylab="Ainit")