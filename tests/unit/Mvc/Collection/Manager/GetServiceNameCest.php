<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Collection\Manager;

use UnitTester;

/**
 * Class GetServiceNameCest
 */
class GetServiceNameCest
{
    /**
     * Tests Phalcon\Mvc\Collection\Manager :: getServiceName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcCollectionManagerGetServiceName(UnitTester $I)
    {
        $I->wantToTest('Mvc\Collection\Manager - getServiceName()');
        $I->skipTest('Need implementation');
    }
}
