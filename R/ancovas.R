ancovas <- function(y, ina, x, logged = FALSE) {
  ni <- tabulate(ina)
  a <- sort_unique.length(ina) 
  N <- length(ina)
  sy <- colsums(y)
  sx <- sum(x)
  com <- sy^2/N
  com2 <- sx * sy / N
  syy <- colsums(y^2) - com
  sxx <- sum(x^2) - sx^2/N
  sxy <- colsums(x * y) - com2
  tyy <- colsums( rowsum(y, ina)^2/ni ) - com
  txx <- sum( rowsum(x, ina)^2/ni ) - sx^2/N
  txy <- colsums( as.vector( rowsum(x, ina)/ni ) * rowsum(y, ina) ) - com2
  eyy <- syy - tyy
  exx <- sxx - txx
  exy <- sxy - txy
  b <- exy / exx
  sse <- eyy - exy^2/exx
  sse2 <- syy - sxy^2/sxx
  dof <- N - a - 1
  mse <- sse / dof
  ftreat <- (sse2 - sse)/(a - 1) / mse
  fb <- sxy^2/sxx/mse
  pvaltreat <- pf(ftreat, a - 1, dof, lower.tail = FALSE, log.p = logged) 
  pvalb <- pf(fb, 1, dof, lower.tail = FALSE, log.p = logged) 
  res <- cbind(ftreat, fb, pvaltreat, pvalb)
  colnames(res) <- c("Ftreat", "Fbeta", "pvalue-treat", "pvalue-beta")
  res
} 
  
   