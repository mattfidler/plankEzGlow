setwd("~/qmk_firmware/keyboards/planck/ez/glow/keymaps/mattfidler")

zip <- file.info(list.files("~/Downloads", pattern="planck_ez_glow.*[.]zip$", full.names = TRUE))
zip <- rownames(zip)[which.max(zip$mtime)]

temp.dir <- tempfile("keymap")
dir.create(temp.dir)

withr::with_dir(temp.dir, unzip(zip))

key.source <- list.files(temp.dir, pattern="_source", full.names = TRUE)

keymap.c <- gsub(" SS_DELAY(100)", "", readLines(file.path(key.source, "keymap.c")), fixed=TRUE)
keymap.c <- gsub("SEND_STRING(SS_TAP(X_KP_2))", "SEND_STRING(\"matthew.fidler@gmail.com\")",
                 keymap.c, fixed=TRUE)

w <- which(regexpr("process_record_user", keymap.c) != -1)
if (length(w) == 1 && keymap.c[w + 9] == "}") {
  keymap.c <- c(keymap.c[seq(1, w - 1)],
                readLines("process_record_user.c"),
                keymap.c[-seq(1, w + 9)])
} else {

  w <- which(regexpr("case RGB_SLD:", keymap.c) != -1)

  if (length(w) == 1 && keymap.c[w + 7] == "}") {

    user <- readLines("process_record_user.c")
    w2 <- which(regexpr("case RGB_SLD:", user) != -1)
    if (length(w2) == 1) {
      user <- user[-seq(1, w2 - 1)]
    } else {
      stop("cant figure out record user")
    }

    keymap.c <- c(keymap.c[seq(1, w - 1)],
                  user,
                  keymap.c[-seq(1, w + 7)])
  } else {
    stop("keymap input has changed")
  }

}

w <- which(regexpr("tap_code16(KC_K)", keymap.c, fixed=TRUE) != -1)

if (length(w) > 1 && regexpr("on_dance_", keymap.c[w[1] - 2]) != -1 && keymap.c[w[1]+7] == "}") {
  keymap.c <- c(keymap.c[seq(1, w[1] - 2)],
                "    if(state->count >= 3) {",
                "      tap_code16(KC_APPLICATION);",
                "      for (uint8_t i = 2; i < state->count; i++) {",
                "        tap_code16(KC_K);",
                "      }",
                "    }",
                keymap.c[-seq(1, w[1] + 6)])
} else {
  warning("tap dance k not modified")
}

writeLines(keymap.c, "keymap.c")
writeLines(readLines(file.path(key.source, "rules.mk")), "rules.mk")
writeLines(c(readLines(file.path(key.source, "config.h")),
             "#define TAPPING_TERM_PER_KEY"), "config.h")
