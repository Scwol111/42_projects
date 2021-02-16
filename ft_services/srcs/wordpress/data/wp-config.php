<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'admin' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql:3306' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         't7tu|N[R@bB{8tHsJm}XU7)/}UT?2X+Lvqu1*9Cx Xl~xNs,){vx.(A#f8D2/4y_' );
define( 'SECURE_AUTH_KEY',  '0AMGo[7.3MFl6d*5ab]jj|/iN$=wWCdXu*p!j<ZHPzrU/Sr)cq|!2XHh$bEsGcb7' );
define( 'LOGGED_IN_KEY',    'Z)vzh~]F}8eTH@Z$%,gU4bo$V}&z=Bh,^<Yi%- dSs`s}q[bk%Fq$baS5#gy8-Uh' );
define( 'NONCE_KEY',        ',j6WPs/65_ Ec}%K&r~i(`FhBbt7!- Ms4^OS%rAl$8^f171=5}E#yog93?YyXVa' );
define( 'AUTH_SALT',        'K*;vG$:J9_Q !60pDRBZEsb:N%@FxHhv<jTlJjSs?jgAV]~c2I:a,YR=Z[A@p8ix' );
define( 'SECURE_AUTH_SALT', 'dDq2f8F-(zFTR$C-(z1B`YM<y[#4HY);D3w5X6C(O~,<_Gr8d2vO*tR 2No*~[Sd' );
define( 'LOGGED_IN_SALT',   'MIaTE1x%z /&rZS3P)z,8w/M0uIG3^O95QE>jSPMz|5/*U#jT7Wf61m[SaP}$:.P' );
define( 'NONCE_SALT',       'zI-;|lnAesrMV>&}tCrNht)1ni$o6,(<)*BR nDCkz1kOcp<dJ[8-0K75ENvL9fu' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';