<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Cacheable;

use Phalcon\Mvc\Model as PhalconModel;

class Parts extends PhalconModel
{
    public function initialize()
    {
        $this->hasMany(
            'id',
            RobotsParts::class,
            'robots_id',
            [
                'alias' => 'RobotsParts',
            ]
        );
    }
}
